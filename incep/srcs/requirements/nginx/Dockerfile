FROM debian:oldstable

RUN apt-get update -y && apt-get upgrade -y
RUN apt install nginx -y && apt install openssl -y

COPY /conf/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /etc/nginx/ssl && mkdir -p /var/run/nginx
RUN	openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=KR/ST=서울특별시/L=강남구/O=42/OU=seoul/CN=minseunk.42.kr/UID=minseunk"

EXPOSE 443

CMD	[ "nginx", "-g", "daemon off;" ]