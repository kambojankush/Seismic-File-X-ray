# Sesmic-File-X-ray
This project is to extract the desired information from seismic (SEG-Y) file into text format from seismic file headers.
This information can then be utilised for desired analysis without the need to graphically display information; thus avoiding the use of huge RAM and GPU.

Project uses a JavaFX application to display the extracted information.

## What is SEG-Y?
The SEG-Y (sometimes SEG Y) file format is one of several standards developed by the [Society of Exploration Geophysicists](https://en.wikipedia.org/wiki/Society_of_Exploration_Geophysicists "Wikipedia") (SEG) for storing geophysical data. It is an open standard, and is controlled by the SEG Technical Standards Committee, a non-profit organization.

## Extracted Information:
The information extracted from SEG-Y file is stored as:
* **Text Header**: Text file
* **Binary Header**: Text File
* **Extended Textual File Header**: Text File
* **Trace Header**: CSV File
* **Data Samples**: CSV File

***
## Screenshots:

![alt tag](https://github.com/kambojankush/Sesmic-File-X-ray/blob/master/screens/Screenshot1.png?raw=true "1")

![alt tag](https://github.com/kambojankush/Sesmic-File-X-ray/blob/master/screens/Screenshot2.png?raw=true "2")

***
### Files:

**ReadHeaders.cpp**: To Extract Text Header, Binary Header, Extended Textual File Headers & Trace Headers.

_Usage: ./ReadHeaders filename.sgy {textheader}.txt {binaryheader}.txt {extendedtextheader}.txt {traceheader}.csv_

**ReadData.cpp**: To extract Trace Samples of a given trace. (Can pass Sample no. to skip initial samples)

_Usage: ./ReadData filename.sgy [trace no] [sample no] [no of ext txt headers]_

[ ]: Optional (Default first trace no & sample no)

**plot.py**: Plot a given trace using matplotlib (Reads trace data from the output file given by ReadData; Not implemented in application)

_Usage: python3 plot.py_ 
***

## Current Known Limitations:
* Variable Extended Textual File Headers are not supported
* Only "4-byte IBM floating-point" Data Sample format supported
* Text Headers and Extended Textual File Headers assumed to be in EBCDIC format
