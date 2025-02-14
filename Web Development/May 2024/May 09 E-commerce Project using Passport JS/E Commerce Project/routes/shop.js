const path = require('path');
const express = require('express');

const router = express.Router();
const {route} = require('./admin');

const shopController = require('../controller/shop');

router.get('/', shopController.getHome);
router.get('/products/:id', shopController.getProductsById);
router.get('/cart', shopController.getCart);
router.get('/cart/add/:id', shopController.getAddToCartById);
router.get('/cart/increase/:id', shopController.getIncrease);
router.get('/cart/decrease/:id', shopController.getDecrease);
router.get('/cart/buy', shopController.getCartBuy);
router.get('/order/history', shopController.getOrderHistory);
router.get('/product/details/:id', shopController.getProductDetails);

module.exports = router;