// server.js
const express = require('express');
const app = express();

app.use(express.json()); // for parsing JSON

app.post('/add-to-cart', (req, res) => {
    console.log('Received item:', req.body);
    res.json({ status: 'success', item: req.body });
});

app.listen(3000, () => {
    console.log('Server running at http://localhost:3000');
});
