# TrinityCore-3.3.5a.12340
* 支持eluna脚本

# Ubuntu 16.04.7系统下编译
## 1、更新系统
* apt-get update

## 2、安装基础库
apt-get install libssl-dev libbz2-dev libreadline-dev libmysqlclient-dev libncurses-dev

## 3、安装gcc8.4
* add-apt-repository ppa:ubuntu-toolchain-r/test
* apt-get update
* apt-get install gcc-8 g++-8
* sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 100
* sudo update-alternatives --config gcc
* sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-8 100
* sudo update-alternatives --config g++

## 4、安装mysql5.7.33
* apt-get install mysql-server

* mysql -u root -p
> GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'Jll9496././' WITH GRANT OPTION;

> FLUSH PRIVILEGES;

### 4.1、修改IP
> vi /etc/mysql/mysql.conf.d/mysqld.cnf

> bind-address = 0.0.0.0

> :wq

* service mysql restart

## 5、编译安装cmake3.11.4
* tar zxvf cmake-3.11.4.tar.gz
* cd cmake-3.11.4/
* ./configure
* make && make install

## 6、编译安装boost库1.67
* tar zxvf boost_1_67_0.tar.gz
* cd boost_1_67_0
* ./bootstrap.sh --with-libraries=system,filesystem,iostreams,program_options,regex
* ./b2
* ./b2 install

## 7、拉取源码
* git clone https://gitee.com/jiangjiali/TrinityCore
* cd TrinityCore/
* mkdir build
* cd build/

### 7.1、编译TrinityCore
* cmake ../ -DCMAKE_INSTALL_PREFIX=/root/wow -DCONF_DIR=/root/wow/etc -DCMAKE_BUILD_TYPE=Release -DTOOLS=1 -DWITH_WARNINGS=1
* make authserver
* make worldserver