<?php
/**
 * Autocomplete
 *
 * Returns DBPedia autocomplete as JSON
 */
function lookup_dbpedia_autocomplete($q)
{
  $dbpedia_base = "http://lookup.dbpedia.org/api/search.asmx/PrefixSearch?QueryClass=&MaxHits=5&QueryString=";
  $query        = $q;
  $query        = str_replace(" ", "_", $query);
  $result = drupal_http_request($dbpedia_base . $query);
	
  if (isset($result) && in_array($result->code, array('200','302','307')) && $result->data != '')
	{
    $xml     = simplexml_load_string($result->data);
    $lookups = array();
    foreach ($xml as $result){
      $lookups[(string) $result->Label . ' [' . (string) $result->URI . ']'] = (string) $result->Label;
    }
    print drupal_json($lookups);
    exit();
  } else {
    $error = array('Error' => $result->code);
    print drupal_json($error);
    exit();
  }
}