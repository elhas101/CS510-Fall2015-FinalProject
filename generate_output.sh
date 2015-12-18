
echo "Executing juliaset and mandelbrot..."
# Execute make for julia and mandelbrot
(cd C-JuliaSets && make julia)
(cd Cpp-Mandelbrot && make mandelbrot)

echo "Generating datafiles..."
# Generate default csv datafiles in main directory
C-JuliaSets/julia -2 2 -2 2 1920 1920 -1.037 0.17 > juliaset.csv
Cpp-Mandelbrot/mandelbrot -2 2 -2 2 1920 1920 > mandelbrot.csv 