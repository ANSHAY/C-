# TODO:

1. Read raw image - take filename as input argument
2. Demosaic the raw image to get RGB image
3. Apply White Balance
4. Apply Brightness and Gamma correction

# References, Literature

Demosaicing

1. https://en.wikipedia.org/wiki/Raw_image_format#File_contents
2. https://stackoverflow.com/questions/6539047/raw-image-file-what-format-is-my-data-in

3. https://stackoverflow.com/questions/33756723/machine-vision-8bit-bayer-rggb-to-rgb-in-open-cv
4. https://stackoverflow.com/questions/72499553/convert-raw-image-in-bayer-encoding-rggb-and-16-bit-depth-to-rgb-final-image
5. https://docs.opencv.org/3.4/d8/d01/group__imgproc__color__conversions.html#ga57261f12fccf872a2b2d66daf29d5bd0

WB

1. https://stackoverflow.com/questions/49835662/how-to-use-xphoto-whitebalancer-balancewhite-with-python-and-opencv

Gamma correction

1. https://lindevs.com/apply-gamma-correction-to-an-image-using-opencv

# Requirements

1. Opencv: https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html
2. Opencv-contrib (xphoto)
3. Argparse:
   run this if error in downloading -
   `git config --global --add safe.directory /path/to/dir/griffyn/build/_deps/argparse-src`
