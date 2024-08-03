docker run --rm -it `
    --privileged `
    --name DevContainer `
    -v ${PWD}/../stages:/root/stages `
    devcontainer
