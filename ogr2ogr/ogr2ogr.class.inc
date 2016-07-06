<?php

/**
 * Could also implement Iterator: http://php.net/manual/en/class.iterator.php
 */
class Ogr2ogr {
  var $ogr2ogr = '';
  var $uri = '';

  function __construct($uri) {
    if ($ogr2ogr_path = exec('which ogr2ogr')) {
      $this->ogr2ogr = $ogr2ogr_path;

      // TODO: Check that file exists at $uri
      // TODO: Perhaps $uri should be an array of strings rather than a string to allow for multiple uri's.
      $this->uri = $uri;
    }
  }

  function process($args = array()) {
    if ($this->ogr2ogr) {
      if ($this->uri) {
        $result = array();

        $command = $this->ogr2ogr .' -f CSV /vsistdout/ "'. $this->uri .'"';
        foreach ($args as $flag => $value) {
          $command .= ' '. $flag .' '. $value;
        }

        // Can also seek to arbitrary features quite easily, for example:
        //   ogr2ogr -f CSV /vsistdout/ Existing_Developments_WGS84.shp  -lco GEOMETRY=AS_WKT -where 'fid in (1,2,3,4,5)'

        // Grab CSV formatted WKT data
        // TODO: Set up a try/catch block here
        if (($handle = popen($command, "r")) !== FALSE) {
          $header = array();
          while (($data = fgetcsv($handle)) !== FALSE) {
            // Hold onto the header so we can map to fields.
            if (empty($header)) {
              $header = $data;
            }
            else {
              $result[] = array_combine($header, $data);
            }
          }
          fclose($handle);
        }
        else {
          throw new Exception('ogr2ogr could not execute');
        }

        return $result;
      }
    }
  }

  function getWkt($proj = 'EPSG:4326') {
    $args = array(
      '-lco' => 'GEOMETRY=AS_WKT',
      '-t_srs' => $proj,
    );
    return $this->process($args);
  }
}
