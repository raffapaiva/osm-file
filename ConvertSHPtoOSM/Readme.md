Conversion shell script
=======================

A tool for autoconvert the shapefiles into .osm data using the default configuration

Usage
---

to run the scripe, use ./convertosm [dir], changing dir by the folder where the shapefiles are localized, the files dir must be the directory where you can found the folder, not only the .shp files(for a better conversion, the .dbf .prj .sbn .sbx and .shx are necessary).

The python bindings are also necessary to execute and interpret the main part of the script.

=========================================================================================================================================================================================================================


ogr2osm.py
==========

A tool for converting ogr-readable files like shapefiles into .osm data


Installation
------------

ogr2osm requires gdal with python bindings. Depending on the file formats 
you want to read you may have to compile it yourself but there should be no 
issues with shapefiles. On Ubuntu you can run `sudo apt-get install -y python-gdal python-lxml` to get
the software you need.

It also makes use of lxml. Although it should fall back to builtin XML implementations seamlessly these are less likely to be tested and will most likely run much slower.

This version of ogr2osm is based on [Iván Sánchez Ortega](https://github.com/pnorman/ogr2osm)<ivan@sanchezortega.es>


About
-----

This version of ogr2osm is based on 
[Andrew Guertin's version for UVM](https://github.com/andrewguertin/ogr2osm)
which is in turn based on Ivan Ortega's version from the OSM SVN server.

ogr2osm will read any data source that ogr can read and handle reprojection for 
you. It takes a python file to translate external data source tags into OSM 
tags, allowing you to use complicated logic. If no translation is specified it 
will use an identity translation, carrying all tags from the source to the .osm 
output. 

Import Cautions
---------------
Anyone planning an import into OpenStreetMap should read and review the import 
guidelines located [on the wiki](http://wiki.openstreetmap.org/wiki/Import/Guidelines). 
When writing your translation file you should look at other examples and 
carefully consider each external data source tag to see if it should be 
converted to an OSM tag.

The translations files can be found on https://github.com/pnorman/ogr2osm

Usage
-----
if it's necessary to convert the shapefiles using another configuration, not the default one, the following options are necessary:

	Usage: ogr2osm.py SRCFILE

	Options:
	  -h, --help            show this help message and exit
	  -t TRANSLATION, --translation=TRANSLATION
							Select the attribute-tags translation method. See the
							translations/ directory for valid values.
	  -o OUTPUT, --output=OUTPUT
							Set destination .osm file name and location.
	  -e EPSG_CODE, --epsg=EPSG_CODE
							EPSG code of source file. Do not include the 'EPSG:'
							prefix. If specified, overrides projection from source
							metadata if it exists.
	  -p PROJ4_STRING, --proj4=PROJ4_STRING
							PROJ.4 string. If specified, overrides projection from
							source metadata if it exists.
	  -v, --verbose         
	  -d, --debug-tags      Output the tags for every feature parsed.
	  -f, --force           Force overwrite of output file.
	  --encoding=ENCODING   Encoding of the source file. If specified, overrides
							the default of utf-8
	  --significant-digits=SIGNIFICANTDIGITS
							Number of decimal places for coordinates
	  --rounding-digits=ROUNDINGDIGITS
							Number of decimal places for rounding
	  --no-memory-copy      Do not make an in-memory working copy
	  --no-upload-false     Omit upload=false from the completed file to surpress
							JOSM warnings when uploading.
	  --id=ID               ID to start counting from for the output file.
							Defaults to 0.
