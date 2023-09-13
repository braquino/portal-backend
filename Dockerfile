FROM c-build:0.0.1 as builder

WORKDIR /portal-backend

COPY . .

RUN mkdir build-rls
RUN cmake -S . -B build-rls -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build-rls



FROM debian:bookworm-slim as production

WORKDIR /etc/portal-backend

COPY --from=builder /portal-backend/build-rls/portal-backend .

RUN apt -y update
RUN apt -y install libpq5 libfmt-dev

CMD [ "./portal-backend" ]