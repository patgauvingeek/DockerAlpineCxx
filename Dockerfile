#FROM gcc AS build-man
FROM alpine AS build-man

RUN apk update && apk add --no-cache \ 
    autoconf build-base binutils cmake curl file gcc g++ git libgcc libtool linux-headers make musl-dev ninja tar unzip wget
COPY main.cxx main.cxx
RUN g++ -std=gnu++20 main.cxx -o compute

FROM alpine
RUN apk update && apk add --no-cache \ 
    libstdc++
COPY --from=build-man compute /compute
RUN chmod +x /compute
CMD [ "./compute" ]
