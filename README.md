# node addons

**NodeJs Addons** is a repository which shows different JavaScript objects
exported through the v8 api.

If there are any issues which have cost you a lot of time figuring out - or
you want to add some more complexity, then feel free to hack.

## Installation

    npm install node-addons
    
then hope it compiles - our manually do

    cd ./node_modules/node-addons && make build

finally you can use any compiled example with **require**

    var addons = require('node-addons');

    console.log(addons.string.value);
    console.log(addons.string.greet('Bodo'));

## Content

Currently there are examples for following objects:

### Boolean

* [code](http://github.com/bodokaiser/node-addons/blob/master/src/boolean.cc)
* [test](http://github.com/bodokaiser/node-addons/blob/master/test/boolean.js)

### Number

* [code](http://github.com/bodokaiser/node-addons/blob/master/src/number.cc)
* [test](http://github.com/bodokaiser/node-addons/blob/master/test/number.js)

### String

* [code](http://github.com/bodokaiser/node-addons/blob/master/src/string.cc)
* [test](http://github.com/bodokaiser/node-addons/blob/master/test/string.js)

### Object

* [code](http://github.com/bodokaiser/node-addons/blob/master/src/object.cc)
* [test](http://github.com/bodokaiser/node-addons/blob/master/test/object.js)

### Array

* [code](http://github.com/bodokaiser/node-addons/blob/master/src/array.cc)
* [test](http://github.com/bodokaiser/node-addons/blob/master/test/array.js)

### Buffer

* [code](http://github.com/bodokaiser/node-addons/blob/master/src/buffer.cc)
* [test](http://github.com/bodokaiser/node-addons/blob/master/test/buffer.js)

### Function

* [code](http://github.com/bodokaiser/node-addons/blob/master/src/function.cc)
* [test](http://github.com/bodokaiser/node-addons/blob/master/test/function.js)

### Prototype

* [code](http://github.com/bodokaiser/node-addons/blob/master/src/prototype.cc)
* [test](http://github.com/bodokaiser/node-addons/blob/master/test/prototype.js)

## License

Copyright © 2013 Bodo Kaiser <i@bodokaiser.io>

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
