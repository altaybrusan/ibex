% TVL1denoise demo
%
% Manolis Lourakis 2016

im=imread('noisyLena.png');
imshow(im);

outim=TVL1denoise(im, 100, 100);
figure; imshow(outim, []);
