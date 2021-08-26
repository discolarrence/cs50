-- write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Johnny Depp.
-- You may assume that there is only one person in the database with the name Helena Bonham Carter.
SELECt title FROM movies WHERE id IN (SELECT movie_id FROM stars JOIN people ON stars.person_id = people.id WHERE name = "Johnny Depp") AND id IN (SELECT movie_id FROM stars JOIN people ON stars.person_id = people.id WHERE name = "Helena Bonham Carter");