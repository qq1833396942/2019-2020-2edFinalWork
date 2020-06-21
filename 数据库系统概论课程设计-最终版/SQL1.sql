create table HK		                            /*户口信息表*/
( Hno char(20) primary key not null,	/*户号*/
Hname char(20) not null,              	/*户主姓名*/
ID char(20) not null,							/*身份证号*/
Nation char(20) not null,					/*民族*/
Ads varchar(20) not null,					/*住址*/
Indate Datetime not null,					/*迁入时间*/
wherein varchar(20) not null,				/*何地迁入*/
Outdata Datetime,							/*迁出日期*/
Whereout varchar(20));						/*迁往何地*/

create table RK									/*人口信息表*/
( Rname char(20) not null,
Rsex char(2) not null,
ID char(20) primary key not null,
Nation char(20) not null,
Province char(20) not null,
Birdate Datetime not null,
Birpace varchar(20),
Ads varchar(20));

create table GL									/*管理员信息表*/
( Gname char(20) not null,
Number char(20) primary key not null,
Sex char(2),
Paswd varchar(20) not null);

create table RIN								/*人口迁入信息表*/
( Hno char(20) not null,
Relation char(20) not null,
ID char(20) not null,
Indate Datetime not null,
wherein varchar(20) not null,
bollout char(20) not null,
foreign key (Hno) references HK(Hno),
foreign key(ID) references RK(ID));

