// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include "xid.h"

#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkTIFFReader.h>
#include <vtkRenderWindow.h>
#include <vtkImageData.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkImageReader2Factory.h>
#include <vtkRenderer.h>


int main()
{
#pragma region INITIALIZATION

	printf("Initializing application...");
	if (!mclInitializeApplication(NULL, 0))
	{
		printf("Failed to initialize application");
		_getch();
		return -1;
	}
	else
	{
		printf("Done.\n");
	}

	printf("Initializing library...");
	if (!xidInitialize())
	{
		printf("Failed to initialize library");
		_getch();
		return -1;
	}
	else
	{
		printf("Done.\n");

	}

#pragma endregion
	
	// main code here
	
	vtkSmartPointer<vtkImageReader2> imageReader;
	vtkSmartPointer<vtkImageReader2Factory> imageFactory;
	imageReader.TakeReference(imageFactory->CreateImageReader2("READ FILE")); //C:/temp/113.tiff
	if (!imageReader)
	{
		printf("\nfailed to read image ");
		_getch();
		return -1;
	}
	
	//Read image
	imageReader->SetFileName("C:/temp/113.tiff");
	imageReader->Update();
	printf("image is read \n ");

	vtkSmartPointer<vtkImageData> _imgData =
		vtkSmartPointer<vtkImageData>::New();
	_imgData = imageReader->GetOutput();
	int dims[3];
	_imgData->GetDimensions(dims);
	printf("\n dim[0] : %d dim[1] : %d dim[2] : %d", dims[0], dims[1], dims[2]);
	printf("\nBit depth : %s", _imgData->GetScalarTypeAsString());
	
	//__int16 ** _buf = new __int16*[dims[0]];
	//for (int i = 0; i<dims[0]; i++)
	//	_buf[i] = new __int16[dims[1]];

	
	mwArray mwImg((mxInt32)dims[0], (mxInt32)dims[1], mxUINT16_CLASS);
	mwArray xd((mxInt32)dims[0], (mxInt32)dims[1], mxDOUBLE_CLASS);
	for (size_t i = 0; i < dims[0]; i++)
	{
		for (size_t j = 0; j < dims[1]; j++)
		{
			__int16* pixel = static_cast<__int16*>(_imgData->GetScalarPointer(i, j, 0));
			//_buf[i][j] = *pixel;
			mwImg(i+1,j+1) = (mxUint16)(*pixel);
		}
	}

	mxUint16 mxVal;
	mwImg(1,1).GetData(&mxVal, 1);
	printf("\nfirst pixel value : %d",mxVal);
	
	xid(1, xd, mwImg,(mwArray)0.6);

	printf("\n Press any key to start termination.");
	_getch();
	
#pragma region TERMINATION

	printf("\nTerminating library...");
	xidTerminate();
	printf("Done.\n");

	printf("Terminating application...");
	if (!mclTerminateApplication())
	{
		printf("Failed to terminate application");
		_getch();
		return -1;
	}
	else
	{
		printf("Done.\n");
	}


#pragma endregion




    return 0;
}

