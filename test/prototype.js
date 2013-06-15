describe('Prototype', function() {

    var chai = require('chai');
    var Prototype = require('../build/Release/prototype');

    it('should return an instance of Prototype', function() {
        var proto = new Prototype('test');

        chai.expect(proto).to.be.an.instanceof(Prototype);
    });

    describe('#get', function() {

        it('should return "test"', function() {
            var proto = new Prototype('test');

            chai.expect(proto.get('name')).to.equal('test');
        });

    });

    describe('#set', function() {

        it('should set "hello" to "world"', function() {
            var proto = new Prototype('test');

            proto.set('hello', 'world');

            chai.expect(proto.get('hello')).to.equal('world');
        });

    });

});
