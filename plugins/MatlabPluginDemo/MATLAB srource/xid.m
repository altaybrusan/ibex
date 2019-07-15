function [out_img] = xid(input_image,max_Lambda,filename) 
% x-ray image denoising tool
%   compare wavelet, NLM and TV-L1 denoising performance.
%   incoming images are denoised and both denoised and difference image (input-defoised)
%   for each filter are saved. In addition, the SNR, PSNR, RMSE of each
%   filter is saved in a report excel file. 
%   output: just the wavelet denoised image is returned back.
%   Gaussian(LoG) and compared to each other.

% control the input data class
if(not(isa(input_image,'uint16')))
    out_img =input_image;
    return;
end

 if ~exist('filename','var')
     % third parameter does not exist, so default it to something
      filename = '[]';
 end
 
 filename = convertCharsToStrings(filename);

%normalize input image
norm_in = mat2gray(input_image);
result_Tbl = table({'empty'},0,0,0,0,'VariableNames',{'Filter','SNR','PSNR', 'RMSE', 'parameter'});
figure();

%% Wavelet denoising section 
fprintf('\nExecuting wavelet.');
[thr,sorh,keepapp] = ddencmp('den','wv',input_image);

% wavelet based denoise image
wden_img = wdencmp('gbl',double(input_image),'sym4',2,thr,sorh,keepapp);
% normalize pixel intensity
norm_wden = mat2gray(wden_img);
% absolute difference image
nom_wdiff = imabsdiff(norm_in,norm_wden);
% rescale difference image 
r_wdiff = uint16(wcodemat(nom_wdiff,double(intmax('uint16'))));
% rescale denoised image
r_wden = uint16(wcodemat(norm_wden,double(intmax('uint16'))));
% produce output image
out_img = r_wden;

% write images
imwrite(r_wden,sprintf('wden_image_%s.png',filename));
imwrite(r_wdiff,sprintf('wdiff_image_%s.png',filename));

% plot images
plt1 = subplot(3,2,1);
histogram(r_wden);
title('wavelet denoised image histogram (a)');
plt1.YRuler.Exponent = 0; 
plt1.YRuler.TickLabelFormat = '%6d';
plt1.XRuler.Exponent = 0; 
plt1.XRuler.TickLabelFormat = '%6d';
xlabel('pixel intensity','FontWeight','bold','Color','b')
ylabel('pixel count','FontWeight','bold','Color','b')

plt2 = subplot(3,2,2);
histogram(nom_wdiff);
title('normalized difference histogram (b)');
xlim([0 max(nom_wdiff(:))])
plt2.YRuler.Exponent = 0; 
plt2.YRuler.TickLabelFormat = '%6d';
xlabel('normalized pixel intensity','FontWeight','bold','Color','b')
ylabel('pixel count','FontWeight','bold','Color','b')

fprintf('\nWavelet denoising performance is calculating...');
[peaksnr1, snr1] = psnr(norm_wden,norm_in);
mse1 = sqrt(immse(norm_wden,norm_in));
row ={{'wavelet'},snr1,peaksnr1,mse1,0};
result_Tbl =[result_Tbl;row];
 
%% NLM Section
fprintf('\nExecuting NLM.');
% nlm based denoised image 
[nlmden_img,estDoS] = imnlmfilt(double(input_image));
% normalize pixel intensity
nom_nlmden = mat2gray(nlmden_img);
% absolute difference image
nom_nlmdiff = imabsdiff(norm_in,nom_nlmden);
% rescale difference image 
r_nlmdiff = uint16(wcodemat(nom_nlmdiff,double(intmax('uint16'))));
% rescale denoised image
r_nlmden = uint16(wcodemat(nom_nlmden,double(intmax('uint16'))));

% write images
imwrite(r_nlmden,sprintf('nlmden_image_%s.png',filename));
imwrite(r_nlmdiff,sprintf('nlmdiff_image_%s.png',filename));

% plot images
plt1 = subplot(3,2,3);
histogram(r_nlmden);
title('NLM denoised image histogram (c)');
plt1.YRuler.Exponent = 0; 
plt1.YRuler.TickLabelFormat = '%6d';
plt1.XRuler.Exponent = 0; 
plt1.XRuler.TickLabelFormat = '%6d';
xlabel('pixel intensity','FontWeight','bold','Color','b')
ylabel('pixel count','FontWeight','bold','Color','b')

plt2 = subplot(3,2,4);
histogram(nom_nlmdiff);
title('normalized difference histogram (d)');
xlim([0 max(nom_nlmdiff(:))])
plt2.YRuler.Exponent = 0; 
plt2.YRuler.TickLabelFormat = '%6d';
xlabel('normalized pixel intensity','FontWeight','bold','Color','b')
ylabel('pixel count','FontWeight','bold','Color','b')

fprintf('\nNLM denoising performance is calculating...');
[peaksnr1, snr1] = psnr(nom_nlmden,norm_in);
mse1 = sqrt(immse(nom_nlmden,norm_in));
row ={{'NLM'},snr1,peaksnr1,mse1,0};
result_Tbl =[result_Tbl;row];
 
%% TV-L1 denoising section
MIN_Lambda=0.6;
STEP= 0.1;
Iteration=10;
best_snr=-Inf;

for lambda= MIN_Lambda:STEP:max_Lambda
    fprintf('\nExecuting TV-L1 for lambda : %f',lambda);
    % TV-L1 based denoised image 
    tvden_img = TVL1denoise(input_image, lambda, Iteration);
    % normalize pixel intensity
    nom_tvden = mat2gray(tvden_img);
    % absolute difference image
    nom_tvdiff = imabsdiff(norm_in,nom_tvden);
    % rescale difference image 
    r_tvdiff = uint16(wcodemat(nom_tvdiff,double(intmax('uint16'))));
    % rescale denoised image
    r_tvden = uint16(wcodemat(nom_tvden,double(intmax('uint16'))));

    fprintf('\nTV-L1 denoising performance is calculating...');
    [peaksnr1, snr1] = psnr(nom_tvden,norm_in);
     mse1 = sqrt(immse(nom_tvden,norm_in));
    if best_snr<snr1 
        bnom_tvdiff = nom_tvdiff;
        br_tvden = r_tvden; %tvl1_noise_map;
        br_tvdiff = r_tvdiff;
        best_snr = snr1;
    end
    row ={{'TVL1'},snr1,peaksnr1,mse1,lambda};
    result_Tbl=[result_Tbl;row];
end

% write images
imwrite(br_tvden,sprintf('tvden_image_%s.png',filename));
imwrite(br_tvdiff,sprintf('tvdiff_image_%s.png',filename));

% plot images
plt1 = subplot(3,2,5);
histogram(r_tvden);
title('TV-L1 denoised image histogram (e)');
plt1.YRuler.Exponent = 0; 
plt1.YRuler.TickLabelFormat = '%6d';
plt1.XRuler.Exponent = 0; 
plt1.XRuler.TickLabelFormat = '%6d';
xlabel('pixel intensity','FontWeight','bold','Color','b')
ylabel('pixel count','FontWeight','bold','Color','b')

plt2 = subplot(3,2,6);
histogram(bnom_tvdiff);
title('normalized difference histogram (f)');
xlim([0 max(bnom_tvdiff(:))])
plt2.YRuler.Exponent = 0; 
plt2.YRuler.TickLabelFormat = '%6d';
xlabel('normalized pixel intensity','FontWeight','bold','Color','b')
ylabel('pixel count','FontWeight','bold','Color','b')


% Wrire report 
fprintf('\nWriting the result table...\n');
writetable(result_Tbl,sprintf('result_%s.xlsx',filename))


end

