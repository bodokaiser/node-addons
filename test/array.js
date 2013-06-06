var chai = require('chai');

describe('Array', function() {

    var exports = require('../build/Release/array');

    describe('value', function() {

        it('should be an array', function() {
            chai.expect(exports.value).to.be.a('array');
        });

    });

    describe('#push', function() {

        it('should push "Hello World"', function() {
            var arr = [];
            
            exports.push(arr, 'Hello World');

            chai.expect(arr[0]).to.equal('Hello World');
        });

    });

});
