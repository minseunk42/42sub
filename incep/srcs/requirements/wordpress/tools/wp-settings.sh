#!/bin/sh

if [ ! -e /var/www/wordpress/wp-config.php ]; then
	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz
	cp -r ./wordpress/* . && rm -rf ./wordpress
	rm -rf latest.tar.gz
	rm -rf wordpress

	sed -i "s/username_here/$SQL_USER/g" wp-config-sample.php
	sed -i "s/password_here/$SQL_PASSWORD/g" wp-config-sample.php
	sed -i "s/localhost/$WP_DB_HOST/g" wp-config-sample.php
	sed -i "s/database_name_here/$SQL_DATABASE/g" wp-config-sample.php
	cp wp-config-sample.php wp-config.php
	
	wp core install --allow-root --url=$DOMAIN_NAME --title=minseunk123 --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email
	wp user create --allow-root $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PWD
	wp theme install --allow-root zakra
	wp theme activate --allow-root zakra
fi

exec "$@"
