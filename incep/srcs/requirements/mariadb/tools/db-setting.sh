#!/bin/sh

chown -R mysql:mysql /var/lib/mysql
/usr/bin/mysql_install_db

mysqld_safe &
while ! mysqladmin ping -hlocalhost --silent; do
    sleep 2
done

mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$SQL_ROOT_PWD';"
mysql -uroot -p$SQL_ROOT_PWD -e "CREATE DATABASE IF NOT EXISTS $SQL_DATABASE;"
mysql -uroot -p$SQL_ROOT_PWD -e "CREATE USER IF NOT EXISTS '$SQL_USER'@'%' IDENTIFIED BY '$SQL_PASSWORD';"
mysql -uroot -p$SQL_ROOT_PWD -e "CREATE USER IF NOT EXISTS '$SQL_USER'@'localhost' IDENTIFIED BY '$SQL_PASSWORD';"
mysql -uroot -p$SQL_ROOT_PWD -e "GRANT ALL PRIVILEGES ON $SQL_DATABASE.* TO '$SQL_USER'@'%' IDENTIFIED BY '$SQL_PASSWORD';"
mysql -uroot -p$SQL_ROOT_PWD -e "GRANT ALL PRIVILEGES ON $SQL_DATABASE.* TO '$SQL_USER'@'localhost' IDENTIFIED BY '$SQL_PASSWORD';"
mysql -uroot -p$SQL_ROOT_PWD -e "GRANT ALL PRIVILEGES ON $SQL_DATABASE.* TO 'root'@'localhost' IDENTIFIED BY '$SQL_ROOT_PWD';"
mysql -uroot -p$SQL_ROOT_PWD -e "FLUSH PRIVILEGES;"
mysqladmin -uroot -p$SQL_ROOT_PWD shutdown

exec mysqld_safe