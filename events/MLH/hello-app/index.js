const express = require('express');
const app = express();

app.get('/', (req, res) => {
    res.send("<title> My first app </title>Hello You are in the main directory<head><h1> App </h1></head>");
});

app.get('/name', (req, res) => {
    const name = req.query.name;
    // const name = "Anurag";
    res.send(`Hello\nMy name is: ${name}`);
});

app.listen(1234, () => console.log("App started"));