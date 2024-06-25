FROM debian:oldstable

RUN	apt -y update && apt upgrade -y
RUN	apt-get install mariadb-server -y
RUN	apt-get update -y && apt-cache search mariadb

COPY conf/mariadb.conf	/etc/mysql/mariadb.conf.d/mariadb.conf
COPY conf/mariadb.conf	/etc/mysql/my.cnf
COPY tools/database.sh /database.sh

RUN	mkdir -p /run/mysqld
RUN	mkdir -p /var/lib/mysql				
RUN	chmod 755 /var/lib/mysql
RUN chmod 755 /run/mysqld
RUN	chmod +x /database.sh

EXPOSE	3306

ENTRYPOINT ["./database.sh"]