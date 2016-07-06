Merger the shapefiles
=====================================================================================================================

A tool for merge the shp files in one big shp files, with all the layers and information 

Usage
-----

To merge the files, using the default configuration, use the following shell script: 
`for f in *.shp; do ogr2ogr -update -append merged.shp $f -f "ESRI Shapefile"; done;` 
the shell script is responsable to check the shapefiles on the same folder and merge the files, all the files(.dbf, .prj, .sbn, .sbx, .shp and .shx should be on the same folders, not all the files are necessary, however, decrease the change of failure).

The programs necessaries for the merge, including some files necessary for the following parts, can be found and download at <https://trac.osgeo.org/gdal/wiki/DownloadSource>.

It's recommendable to check the files on the <http://www.mapshaper.org> before merge the files, to identify any possible bug, broken files or files with different geometry types.

ATTENTION: the shell script and the ogr2ogr program cannot merge files with different properties, the polygon type files can't be merged with lines or straight lines, ways or any other kind of file, each kinf of file(line, polygon) should be combined individually or you will found a error screen(the code will finish the merge, however, some files will be ignored)

Conversion shell script
=====================================================================================================================

A tool for autoconvert the shapefiles into .osm data using the default configuration.

Usage
---
the code can be used manually by calling the ogr2osm.py with the arguments

to run the script, use `./convertosm [dir]`, changing dir by the folder where the shapefiles are localized, the files dir must be the directory where you can found the folder, not only the .shp files(for a better conversion, the .dbf .prj .sbn .sbx and .shx are necessary).

The python bindings are also necessary to execute and interpret the main part of the script. the download can be done on <https://www.python.org/ftp/python/2.7.12/Python-2.7.12.tar.xz>.

Since the script do the conversion looking at the folders on the dir, please, avoid to let another files on folders on the same directory, to avoid conflict and possible bugs.

it's recommendable to have a backup before converting the files, the code does not check the integrity of the files, which can be check at <http://www.mapshaper.org/> or using another softwares, like JOSM.

another option can be the use of FWTools Binary Distribution, which include all the bindings and files necessary, available at <http://fwtools.loskot.net/>.


Useful information:
===================

the code and the python file are only compatible with the newest version of the osm files, based on the API 0.6 and can be incompatible with the API 0.7 when release.

ogr2osm.py:

A tool for converting ogr-readable files like shapefiles into .osm data.


Installation
------------

ogr2osm requires gdal with python bindings, more information can be found on the webpage <https://pypi.python.org/pypi/GDAL/>. 
Depending on the file formats you want to read you may have to compile it yourself.
The command `'sudo apt-get install -y python-gdal python-lxml'` can be used on Debian based systems to get the necessary software.

It also makes use of lxml. Although it should fall back to builtin XML implementations seamlessly these are less likely to be tested and will most likely run much slower.

This version of ogr2osm is based on [Iván Sánchez Ortega](https://github.com/pnorman/ogr2osm) <ivan@sanchezortega.es>

THE INFORMATION BELOW IS PART OF THE ORIGINAL INFORMATION PROVIDED BY THE DEVELOPER OF THE ogr2osm.py WITHOUT ANY MODIFICATIONS.

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

The translations files can be found on https://github.com/pnorman/ogr2osm .

THE INFORMATION ABOVE IS PART OF THE ORIGINAL INFORMATION PROVIDED BY THE DEVELOPER OF THE ogr2osm.py WITHOUT ANY MODIFICATIONS.

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
							
							
Adding the file on the database
=====================================================================================================================

To access the test database, the following commands should be used on the terminal:
To connect, from terminal:
  `ssh beemap@192.168.0.87`

Ip: 192.168.0.87
User: beemap
Pw: dabeeo0228

to access the database by the pgAdmin3(or any other client), the information can be found below:

Database:
  Name: gis_converter
  User: beemap
  Pw: dabeeo0228
  Port: 5432
(information of the used database)

Connect in any other database using the following names:
  gis_dev
  gis_jeju
  gis_koera
  gis_paris
  gis_sejong
  gis_seoul_en
On the terminal:

`psql gis_converter`

Or any other database name, to connect and check the schema.
DO NOT MODIFY ANY OTHER DATABASE. they are just as examples for a better understand.
Using the pgAdmin3, it's easier to sse the database and understand the schema.
You should have a better result if you use a database client before the 9.3 version.
The informations on the database will be useful when you need to add new information on the database.

copy the .osm files to the database

to copy the osm files into the database, the following command should be used on the terminal:
`scp file.osm username@remotehost:/some/remote/directory`

it's more probable that the user don't have access or authorization, to avoid any problems, use the scp command on the root:
scp foobar.txt your_username@remotehost.edu: 
the server will request your password, keep this information in hand.

after copying th files, you can use the mv command to move the files on the desired folder.

usage
------
the program necessary to upload the files on the database is the osm2pgsql, to install the software, follow the instructions on the website: <https://github.com/openstreetmap/osm2pgsql>, the program has more than 44 options, which can be found on the github.
to add the information, found on the .osm file, on the database, the osm2pgsql software shoud be installed on the server

Command:
`osm2pgsql -c -d gis --slim --hstore -C <cache> --flat-nodes <tempFile> <osmData>` 
`<cache> is the cached memory RAM (in MB) that will be used for the parsing, max of 30000 – Eg. 15000(this option is only necessary if the osm file has more than 10Mbs or the codes are running in a slow computer)`
`<tempFile> is a location where a temporary file can be saved – Eg. /home/beemap/tempFile(same as cache)`
`<osmData> is the source data used to parse to database, as a example: ./australia-oceania-latest.osm.pbf(pbf files can be used, but isn't a good or fast option)`
`<flat-nodes> an alternative node store in a file which can use 20GB.(the use is only recommendable if the computer has a SSD and the file has a huge size, more than 100Mbs)`

the default code used to upload the data on the database is:
`./osm2pgsql -s -d gis_converter ../../path/of/file.osm` 
`<-s>Slim mode, used to save memory and use the options, without this option, only the defaut options can be used.`
`<-d>Is the name of the database that will be saved the data`

to update the database, the command is:
`./osm2pgsql -a -s -d gis_converter ../../path/of/file.osm`
`<-a> is the append option, which allows the database to combine the data without subscribe the old data.`


Issues
=====================================================================================================================

Since the shapefiles aren't made by the community, they don't follow the ID rules found on the Open Street Map, which make the osm2pgsql replace the repeatitive information everytime the user update it. to avoid this problem, it's necessary to everytime use the ogr2ogr to merge all the shapefiles before uploading them into the database, it's necessary also to merge the old information with the new one, to avoid repeatitive IDs and redundant information.

some scripts and commands needs to be improved and correct to avoid some bugs and make easy the use of the import.