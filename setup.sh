#!/usr/bin/env bash

if [ ! -d kenlm ]; then
    git clone https://github.com/kpu/kenlm.git
    echo -e "\n"
fi

if [ ! -d openfst-1.6.3 ]; then
    echo "Download and extract openfst ..."
    sudo apt install graphviz
    wget http://www.openfst.org/twiki/pub/FST/FstDownload/openfst-1.8.1.tar.gz
    tar -xzvf openfst-1.8.1.tar.gz
    cd openfst-1.8.1/
    ./configure --enable-far=true
    make -j4
    sudo make install
    echo "export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/usr/local/lib" >> ~/.bashrc
    echo -e "\n"
fi

if [ ! -d ThreadPool ]; then
    git clone https://github.com/progschj/ThreadPool.git
    echo -e "\n"
fi

echo "Install decoders ..."
python setup.py install --num_processes 4
