all: up

up:
	mkdir -p /home/minseunk/data/mariadb
	mkdir -p /home/minseunk/data/wordpress
	docker compose -f ./srcs/docker-compose.yml up -d --build

stop:
	docker stop $(shell docker ps -q)

clean:
	docker container prune -f
	docker image prune -af
	docker volume prune -af
	docker system prune -af
	docker volume rm $(shell docker volume ls -q)

	sudo rm -rf /home/minseunk/data

.PHONY: up stop clean