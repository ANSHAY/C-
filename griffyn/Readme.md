# ISP Assignment for Griffyn

## ISP components

1. Read raw image
2. Demosaic the raw image to get RGB image
3. Apply White Balance
4. Apply Brightness and Gamma correction

# Explaination

## Structure

The code is structured into following directories:

```
--griffyn
  | --bin
  | --build
  | --config
   |--data
      |--input
      |--output
   |--include
   |--src
   |--scripts
   CMakeLists.txt
   Readme.md
   .gitignore
```

1. src: This is the source folder containing C++ code
2. include: Folder for header files
3. data: This folder contains `input` and `output` folders for input and output files respectively. However you can provide the path to input and output directories wherever you wish to store them
4. config: this folder contains the config.json file, however you can store it anywhere and provide that path to the program
5. scripts: this folder contains rough work script in jupyter

## Implementation

The ISP pipeline implements 3 main parts namely Demosaicing, White Balance and Brightness correction. Each part is implemented in its separate class in their respective files.
Another Class called ISP wraps the pipeline around these 3 parts and provides functions to read raw file.
main.cpp reads the config file and calls each part through isp object.

### Demosaicing

I have used bilinear interpolation to implement demosaicing.
The raw image contains pixels in BayerRGGB format.  
![image](bayerrggb.png)

In bilinear interpolation, the pixels are average of the surrounding present pixels.  
For Red and Blue, the algo walks over the red and blue filled pixels and fills the neighbouring empty pixels by 1/4th (4-connected) and 1/8th (8-connected) of the filled pixel value. So teh pixels in essence bleed out to their neighboring pixels in output image. This method helps in calculating the sum of pixels just once and speeding up the process.
Since green pixels are alternating at a difference of 1 pixel, the algo walks over the empty pixels and takes average of neighboring (4-connected) green pixels.

## White Balance

I have added 6 algos for white balance here. You can choose which algo you want to run by setting the `type` parameter in the `config.json` file under `wb` parameters. `type` can take a value from `0-6` for the five algos:

0. PERCENTILE,
1. SIMPLE,
2. GRAYWORLD,
3. LEARNINGBASED,
4. NORMALSUMS,
5. HISTEQ

Algos 1, 2, 3 are the Opencv implementations of white balance.  
Algos 0, 4, 5 are implemented in the code here.

Here is a brief on what these algos do.

- 0. PERCENTILE: This algo takes in a parameter `percentile`. It trims the smallest and largest `percentile` values and then normalizes the result as (val-min)/(max-min) and clips the output to 255 for each channel individually.
- 4. NORMALSUMS: This algo calculates the sum of all values for each channel. Then scales these sums by their maximum value and inverts the result to get gains for each channel. Next, it agin scales the gains by the maximum gain of the three channels. Finally, it scales the channels with the resulting gains of each channel.  
     In essence, this algo scales up the channel with smallest sum based on the sum of channel with largest sum and scales down the channel with the largest sums based on smallest sum. It helps in bringing the tone of channels closer to each other.
- 5. HISTEQ: This algo applies histogram equalization on individual channels.

## Brightness correction

There are two parts to brightness correction:

1. Gamma correction: The values of the pixels are scaled as per the formulae -  
   p = 255\* ((p/255)^(1/gam))
   It is a non-linear scaling of the pixel values.
   For efficient implementation, first a LUT is created which computes inverse gamma power of all values from 0-255 and then maps the pixel values using the LUT.
2. Alpha Beta correction: This amplifies the pixel values by `alpha` and offsets them by `beta`.  
   p = alpha \* p + beta

The values of alpha, beta and gamma can be configured in `config,json` file.

# References

I have referred to the following literature for help with this assignment.

## Demosaicing

1. https://en.wikipedia.org/wiki/Demosaicing
1. https://en.wikipedia.org/wiki/Bayer_filter
1. https://en.wikipedia.org/wiki/Raw_image_format#File_contents
1. https://stackoverflow.com/questions/6539047/raw-image-file-what-format-is-my-data-in
1. https://stackoverflow.com/questions/33756723/machine-vision-8bit-bayer-rggb-to-rgb-in-open-cv
1. https://stackoverflow.com/questions/72499553/convert-raw-image-in-bayer-encoding-rggb-and-16-bit-depth-to-rgb-final-image
1. https://docs.opencv.org/3.4/d8/d01/group__imgproc__color__conversions.html#ga57261f12fccf872a2b2d66daf29d5bd0

## White Balance

1. https://stackoverflow.com/questions/49835662/how-to-use-xphoto-whitebalancer-balancewhite-with-python-and-opencv
2. https://docs.gimp.org/en/gimp-layer-white-balance.html
3. https://www.morethantechnical.com/2015/01/14/simplest-color-balance-with-opencv-wcode/

## Gamma correction

1. https://lindevs.com/apply-gamma-correction-to-an-image-using-opencv

# Requirements

1. Opencv: https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html
2. Opencv-contrib (xphoto)
3. Argparse: (To parse the command line arguments)  
   run this if IDE gives error in downloading -  
   `git config --global --add safe.directory /path/to/dir/griffyn/build/_deps/argparse-src`
4. Jsoncpp

# Build steps

In the parent directory griffyn follow these steps:

```
mkdir build
cd build
cmake ..
make -j8
```

# Usage

`./g_isp --config_file_path ../config/config.json --output_directory ../data/output --input_file_path ../data/input/captures_1.raw --height 2160 --width 3840`

There are 5 parameters in the command:

1. config_file_path : path to the config.json file
2. input_file_path: path to input file
3. output_directory: path to the directory where you want to save the output file
4. height (optional): height of image
5. width (optional): width of image

- `height` and `width` are optional. If not provided, they get the values from config file.
- Assumes 16bit with BayerRGGB format for raw input files.

# Configuration

### config.json

The parameters of ISP can be configured from the config.json file.  
image parameters: `height`, `width`  
White balance: `type`, `percentile`  
Brightness correction: `alpha`, `beta`, `gamma`

For white balance, type is an integer for the type of WB algo you want to use. percentile is used by only the first algo-PERCENTILE and is ignored by others.

0. PERCENTILE,
1. SIMPLE,
2. GRAYWORLD,
3. LEARNINGBASED,
4. NORMALSUMS,
5. HISTEQ

Algos 1, 2 and 3 are the opencv implementations.  
Algos 0, 4, 5 are implemented by me here as explained in a section above.
