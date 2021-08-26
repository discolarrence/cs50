--Songs that feature other artists will include “feat.” in the name of the song.
--Your query should output a table with a single column for the name of each song.
SELECT name from songs WHERE name LIKE "%feat.%";