FROM ubuntu:16.04

RUN apt-get update && apt-get install -y open-cobol python-dev

ADD code /code

CMD ["/code/run.sh"]

