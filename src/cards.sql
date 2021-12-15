create database dogeshop;
use dogeshop;
#drop table cards;
create table cards (title varchar(40), type varchar(10), src varchar(120));
describe cards;

load data infile "C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/cards.csv" into table cards
fields terminated by ',' enclosed by '"'
lines terminated by '\r\n'
ignore 1 rows;

select * from cards;