FROM debian:oldstable

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install mariadb-server -y

COPY conf/mariadb.conf	/etc/mysql/mariadb.conf.d/mariadb.conf
COPY conf/mariadb.conf	/etc/mysql/my.cnf
COPY tools/db-settings.sh tools/db-settings.sh

RUN	mkdir -p /run/mysqld
RUN	mkdir -p /var/lib/mysql				
RUN	chmod 755 /var/lib/mysql
RUN chmod 755 /run/mysqld
RUN	chmod +x /tools/db-settings.sh

EXPOSE	3306

ENTRYPOINT ["sh", "/tools/db-settings.sh"]
