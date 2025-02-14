const products = require('../models/products');

module.exports.postProductsAdd = async (req, res, next) => {
    const {name, price, description, imageUrl, seller} = req.body;
    try{
        await products.create({
            name, 
            price, 
            description, 
            imageUrl, 
            seller
        });
        res.redirect('/admin/products/add');
    }
    catch(err){
        res.send(err);
    }
}

module.exports.getProductsAll = async (req, res, next) => {
    const products = await products.find();
    res.send(products);
}