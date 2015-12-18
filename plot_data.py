#!/usr/bin/python
# -*- coding: utf-8 -*-

import numpy as np
import pandas as pd
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use('Agg')
import sys
from math import sqrt

def main(argv):
   if len(sys.argv) != 2:
      print 'Input file required'
      sys.exit(2)


inputfile = sys.argv[1]
outputimage = str(sys.argv[1])[:-4]
img = outputimage + ".png"

print 'Input file is ', inputfile
print 'Output file is ', outputimage + ".png"

if __name__ == "__main__":
   main(sys.argv[1:])

# Load the csv file to a panda data frame
df = pd.read_csv(inputfile, header=None)


# generate 2d data
dd = int(sqrt(len(df[2])))
x = np.linspace(min(df[1].values),max(df[1].values),dd)
y = np.linspace(min(df[0].values),max(df[0].values),dd)
z = np.reshape(df[2],(dd,dd)).T

# Plots the 2d data
plt.pcolormesh(x,y,z, cmap = plt.cm.hot)
plt.title(outputimage+' data in 2D')
plt.colorbar() # Includes colorbar to the plot
plt.savefig(img) # Saves the plot to an external file with the name saved in the string 'figure'
