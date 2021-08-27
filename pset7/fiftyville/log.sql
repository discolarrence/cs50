-- Keep a log of any SQL queries you execute as you solve the mystery.

--All you know is that the theft took place on July 28, 2020 and that it took place on Chamberlin Street.
--Who the thief is,
--What city the thief escaped to, and
--Who the thief’s accomplice is who helped them escape

--Search crime reports for crimes on that date
SELECT description FROM crime_scene_reports WHERE year = 2020 AND month = 07 AND day = 28 AND street LIKE "%Chamberlin%";
--Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. 
--Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

--Search interviews for courthouse mentions
SELECT name, transcript FROM interviews WHERE year = 2020 AND month = 07 AND day = 28 AND transcript LIKE "%courthouse%";
-- Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. 
-- If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
-- Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, 
-- I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
-- Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. 
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. 
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.

--Find common person from courthouse/atm/phone call
SELECT id, name FROM people WHERE id IN (SELECT person_id FROM bank_accounts JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE year = 2020 AND month = 07 AND day = 28 AND transaction_type LIKE "%withdraw%" AND atm_location LIKE "%Fifer%") AND license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 07 AND day = 28 AND hour = 10 AND minute > 14 AND minute < 26) AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 07 AND day = 28 AND duration < 60);
-- 514354 | Russell
-- 686048 | Ernest

--Find earliest flight tomorrow
SELECT hour, minute, city FROM airports JOIN flights ON airports.id = flights.destination_airport_id WHERE origin_airport_id IN (SELECT origin_airport_id from flights JOIN airports ON flights.origin_airport_id = airports.id WHERE city LIKE "%Fiftyville%") AND year = 2020 AND month = 07 AND day = 29 ORDER BY hour LIMIT 1;
--8 | 20 | London

--Russell or Ernest on flight?
SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number WHERE flight_id IN (SELECT id FROM flights WHERE year = 2020 AND month = 07 AND day = 29 AND hour = 8 AND minute = 20) AND (name = "Russell" OR name = "Ernest");
--Ernest

--Accomplice is phone call receiver
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year = 2020 AND month = 07 AND day = 28 AND duration < 60 AND caller IN (SELECT phone_number FROM people WHERE name = "Ernest"));
--Berthold