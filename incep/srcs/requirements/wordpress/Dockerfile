FROM debian:oldstable

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y wget php php-fpm php-mysql

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY tools/wp-settings.sh wp-settings.sh

RUN mkdir /run/php
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp
RUN chmod +x /wp-settings.sh

WORKDIR /var/www/wordpress/

RUN chown -R www-data:www-data /var/www/wordpress;
RUN chmod -R 777 /var/www/wordpress;

ENTRYPOINT ["./wp-settings.sh"]

EXPOSE 9000

CMD ["/usr/sbin/php-fpm7.4", "-F"]
