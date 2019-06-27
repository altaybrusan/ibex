#-------------------------------------------------
#
# Project created by QtCreator 2018-10-16T12:53:33
#
#-------------------------------------------------

include(../../common/build/build.pri)
include(../../common/build/g++.pri)
include(../../commonconfig.pri)
include(../pluginconfiguration.pri)


TEMPLATE = lib
CONFIG  += plugin
QT      += widgets

TARGET = CompareFilter

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += COMPAREFILTER_LIBRARY
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../../3rd-Party/ctk/include/ctk-0.1 \
               ../../3rd-Party/ctk/include \
               ../../common/include \
               $$(VTK_DIR)/include/vtk-9.0\
               $$(MATLAB_DIR)/include/

message($$(MATLAB_DIR))

LIBS += $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKCore.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKDICOMCore.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKDICOMWidgets.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKCore.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKWidgets.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKWidgetsPlugins.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKWidgets.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKWidgetsPlugins.lib\
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/dcmtls.lib\
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/dcmnet.lib\
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/dcmdata.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/oflog.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/ofstd.lib \

LIBS += $$(VTK_DIR)/lib/QVTKWidgetPlugin.lib \
        $$(VTK_DIR)/lib/vtkInteractionStyle-9.0.lib\
        $$(VTK_DIR)/lib/vtkCommonCore-9.0.lib \
        $$(VTK_DIR)/lib/vtkRenderingOpenGL2-9.0.lib \
        $$(VTK_DIR)/lib/vtkViewsCore-9.0.lib \
        $$(VTK_DIR)/lib/vtkGUISupportQt-9.0.lib \
        $$(VTK_DIR)/lib/vtkRenderingCore-9.0.lib \
        $$(VTK_DIR)/lib/vtkInteractionImage-9.0.lib \
        $$(VTK_DIR)/lib/vtkRenderingImage-9.0.lib \
        $$(VTK_DIR)/lib/vtkIOImage-9.0.lib\
        $$(VTK_DIR)/lib/vtkCommonExecutionModel-9.0.lib\
        $$(VTK_DIR)/lib/vtkInteractionWidgets-9.0.lib\
        $$(VTK_DIR)/lib/vtkRenderingAnnotation-9.0.lib\
        $$(VTK_DIR)/lib/vtkCommonDataModel-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingCore-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingGeneral-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingMath-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingColor-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingSources-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingFourier-9.0.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/asynciocoder.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/gpu.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/gpumexbinder.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libcovrt.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libemlrt.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libeng.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libfixedpoint.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmat.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libMatlabCppSharedLib.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libMatlabDataArray.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libMatlabEngine.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmex.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwacfObjectDetector.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwautonomouscodegen.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwblas.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwblascompat32.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwboxfilter.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwboxfilter3.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwbwdistEDT.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwbwdistEDTFT.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwbwdistEDTFT_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwbwdistEDT_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwbwlookup.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwbwlookup_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwbwpackc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwbwpackctbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwbwunpackc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwbwunpackctbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcannythresholding_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcgir_construct.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcgxert.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoderprofile.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_CodeInstrHostAppSvc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_CodeInstrTgtAppSvc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_CoderAssumpHostAppSvc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_CoderAssumpTgtAppSvc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_connectivity_memunit.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_ParamTuningTgtAppSvc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_RTIOStreamHostAppSvc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_RTIOStreamTgtAppSvc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_target_services.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_ToAsyncQueueTgtAppSvc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_XILHostAppSvc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwcoder_XILTgtAppSvc.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwComputeMetric.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwddist.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwdisparitySGM.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwedgesobelprewitt_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwedgethinning_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwforegroundDetector.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwgetnumcores.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwgrayto16.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwgrayto8.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwgrayxform.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwgrayxform_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwimfilter.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwimlincomb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwimlincomb_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwimreconstruct.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwimregionalmax.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwimterp2d.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwint16touint16.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwint32touint32.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwint8touint8.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwintlut.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwintluttbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwipp.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwippfilter.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwippgeotrans.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwippmedianfilter.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwippreconstruct.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwjpegreader.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwkdtree.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwlapack.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwmathutil.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwmorphop_binary.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwmorphop_binary_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwmorphop_flat.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwmorphop_flat_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwmorphop_nonflat.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwmorphop_nonflat_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwmorphop_ocv.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwmorphop_packed.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwocvgpumex.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwocvmex.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwordfilt2.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwpolyfun.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwremap.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwremaptbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwrgb2gray_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwrgb2hsv_tbb.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwrtiostreamutils.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsdi_raccel.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsearchOrganizedPointCloud.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwservices.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsigstream.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsimulink.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwslexec_parallel.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwslexec_simbridge.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwslexec_simlog.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwslio_clients.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwslio_core.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsltest_raccel.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsl_AsyncioQueue.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsl_fileio.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsl_log_load_blocks.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsl_services.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsl_sfcn_cov_bridge.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsl_sfcn_loader.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsl_simtarget_core.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsl_simtarget_instrumentation.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwsl_solver_rtw.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwstringutil.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwtbbhist.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwuint16toint16.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwvoxelGridFilter.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwxilcomms.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwxilcomms_rtiostream.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwxilutils.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmwxilutils_sl.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libmx.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/libut.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/mclbase.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/mclcommain.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/mclmcr.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/mclmcrrt.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/mclxlmain.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/ne_mli.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/ocrutils.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/physmod_common_external_library_kernel.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/physmod_common_foundation_core_performance.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/physmod_common_foundation_core_util.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/physmod_common_foundation_sli_util.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/rtwcg.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/sf_runtime.lib\
        $$(MATLAB_DIR)//extern/lib/win64/microsoft/SimulinkBlock.lib\
        xid.lib






SOURCES += \
    comparefilter.cpp \
    comparefilterwidget.cpp

HEADERS += \
    ../../common/include/ialgorithm.h \
    comparefilterwidget.h \
    comparefilter.h \
    xid.h\
    comparefilterwidget_global.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    comparefilterwidget.ui
