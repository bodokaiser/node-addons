var chai = require('chai');

describe('Object', function() {

    var exports = require('../build/Release/object');

    describe('value', function() {

        it('should be an object', function() {
            chai.expect(exports.value).to.be.a('object');
        });

    });

    describe('#get', function() {

        it('should equal b for key a', function() {
            var obj = { 'a': 'b' };

            chai.expect(exports.get(obj, 'a')).to.equal('b');
        });

    });

    describe('#set', function() {

        it('should set 200 on key "no"', function() {
            var obj = {};
            
            exports.set(obj, 'no', 200);

            chai.expect(obj).to.have.property('no', 200);
        });

    });

});
