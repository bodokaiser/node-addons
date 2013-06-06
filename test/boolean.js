var chai = require('chai');

describe('Boolean', function() {

    var exports = require('../build/RELEASE/boolean');

    describe('value', function() {

        it('should be false', function() {
            chai.expect(exports.value).to.be.false;
        });

    });

    describe('#exec', function() {

        it('should return true for false', function() {
            chai.expect(exports.exec(false)).to.be.true;
        });

        it('should return false for true', function() {
            chai.expect(exports.exec(true)).to.be.false;
        });

    });

});
