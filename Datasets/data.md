# Summary

The data generation script is executed with the following command: 
> sh ./generate_output.sh

Which generates juliaset.csv and mandelbrot.csv depending on the settings in the generate_output.sh.

Generating 2d plane images of juliaset and mandelbrot are executed with the following command lines: 
>python ./plot_data.py mandelbrot.csv
>python ./plot_data.py juliaset.csv

>sh ./generate_output.sh && python ./plot_data.py mandelbrot.csv && python ./plot_data.py juliaset.csv

Which results in the png images of csv data plotted using python module matplotlib. 

	
## juliaset images
The juliaset images chosen are as follows:

juliaset_original.png >> original juliaset image at settings: 
>C-JuliaSets/julia -2 2 -2 2 1920 1920 -1.037 0.17 > juliaset.csv
This is the image of the original settings of juliaset at higher resolution 1920x1920

juliaset_zoomout.png >> zoom out of juliaset image at settings: 
>C-JuliaSets/julia -10 10 -10 10 1920 1920 -1.037 0.17 > juliaset.csv

Juliaset_zoom1.png >> zoom in at the following settings: 
>C-JuliaSets/julia -1 1 -1 1 1920 1920 -1.037 0.17 > juliaset.csv

## mandelbrot images
The mandelbrot images chosen are as follows:

juliaset_original.png >> original juliaset image at settings: 
>Cpp-Mandelbrot/mandelbrot -2 2 -2 2 1920 1920 > mandelbrot.csv
This is the image of the original settings of mandelbrot at higher resolution 1920x1920

mandelbrot_zoomout.png >> zoom out of mandelbrot image at settings: 
>Cpp-Mandelbrot/mandelbrot -10 10 -10 10 1920 1920 > mandelbrot.csv

mandelbrot_zoom1.png >> zoom in at the following settings: 
>Cpp-Mandelbrot/mandelbrot -1 1 -1 1 1920 1920 > mandelbrot.csv


##Remark: 
The resolution of the image in png format is unaffected by zoom level due to the fact that the data is generated procedurally in both julia and mandelbrot which shows the advantage of such algorithms. 

