# Zachy-Zone-HDD-File-Shredder

## Table of Content 

  - [Table of Content](#table-of-content)
  - [Introduction](#introduction)
  - [Dependencies](#dependencies)
  - [Build](#build)
  - [Run](#run)
  - [Test](#test)


## Introduction
This is a file shredder, built in C++. It is not intended for "secure use" but this program is more built to showcase my personal skills for a resume etc.

This program also uses std::rand, which is not as good as a cryptographically secure pseudorandom number generator. This means that the random bytes might have bias and will have more probability of bias, then when using a cryptographically secure pseudorandom number generator.

This is also not intended to be used on modern SSD drives, and only built for older HDD drives, as its almost impossible to shred a file on SSD, without wiping the entire drive. Not only this, but using a file shredder on a SSD drive will degrade it faster.

As noted in the License file, but reiterated again here  

**I AM NOT RESPONSIBLE FOR ANY DAMAGE YOU MIGHT DO OR INCUR, USING THIS PROGRAM DIRECTLY OR INDIRECTLY. I AM ALSO NOT RESPONSIBLE FOR ANY FILES YOU MIGHT ACCIDENTALLY DELETE, OR FILES THAT CAN BE RECOVERED AFTER SHREDDING THEM USING THIS PROGRAM.**

**THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.**



## Dependencies

The following table summarizes the tools and libraries required to run cpp-backend.

| Dependencies | Min. version | Recommended version |
| :--- | :--- | :--- |
| **G++** | 9.0 | 12.2  |

## Build
Please edit the paths to your GCC and G++ in the makefile. If your using the default system GCC and G++, just comment out the following lines in the makefile
```shell
override CC := ${HOME}/Installed_Programs/gcc-12.2.0/bin/gcc
override CXX := ${HOME}/Installed_Programs/gcc-12.2.0/bin/g++
```

Build using the make file
```shell
make clean ; make release -j $(nproc)
```

## Run
Run the program
```shell
./build/Zachy-Zone-HDD-File-Shredder <FILE TO SHRED>
```
You can also set a custom overwrite amount (default is 10)
```shell
./build/Zachy-Zone-HDD-File-Shredder <FILE TO SHRED> --overwrite <OVERWRITE AMOUNT>
```

You probably will want to add this program to your path
```shell
echo -ne "\nexport PATH=${PATH TO THIS PROGRAM}/build:" >> "${HOME}"/.profile && echo -ne '$PATH' >> "${HOME}"/.profile && source ~/.profile
```

You can then just run the name of the program  
```
Zachy-Zone-HDD-File-Shredder <FILE TO SHRED>
```


## Test
Run the test to check system compatibility
```shell
./build/Zachy-Zone-HDD-File-Shredder --test
```