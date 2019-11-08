create database if not exists dbms_miniproject;
use dbms_miniproject;

create table if not exists web_series
(
    wsid int primary key,
    ws_name varchar(50),
    ws_genre varchar(20),
    no_of_seasons int,
    no_of_episodes int,
    duration number,
    ratings number,
    ws_image image
    -- ws_video video
);

create table if not exists user
(
    userid int primary key,
    username varchar(50),
    passwd varchar(50),
    conpasswd varchar(50),
    email varchar(70)
);