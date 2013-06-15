describe('Function', function() {

    var chai = require('chai');
    var create = require('../build/Release/function');

    describe('#create', function() {

        it('should return a function printing echo', function() {
            var echo = create();

            chai.expect(echo()).to.equal('Hello World');
        });

    });

});
