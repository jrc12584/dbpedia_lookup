dbpedia_lookup
==============

Drupal 6 module - CCK auto-complete field widget for looking up DBPedia URI's and storing the URI and preferred label.

Setup

1. Make sure you have installed Drupal dependency CCK (https://drupal.org/project/CCK)
2. Install the dbpedia_lookup module (sites/all/modules/dbpedia_lookup).
3. Enable in Admin menu > Site building > Modules.
4. Set up user permissions (User > Permissions) to access the dbpedia_lookup callback.
5. Go to manage content types and "Manage Fields".  Add a new field type of "Lookup for DBPedia".
6. Create a new node and use the auto-complete widget to associate content with DBPedia URI's!

TODO:

1. Improve error handling in case DBPedia endpoint is down
2. Improve the URI storage technique.