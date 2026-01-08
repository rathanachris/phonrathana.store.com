const fs = require("fs");

const urls = [
"https://www.phonrthana.stoer.com/home", "https://www.phonrthana.stoer.com/about",
"https://www.phonrthana.stoer.com/shop", "https://www.phonrthana.stoer.com/products" "https://www.phonrthana.stoer.com/review", "https://www.phonrthana.stoer.com/contact",
];
const today = new Date().toISOString().split("T")[0];

let sitemap =
  `<?xml version="1.0" encoding="UTF-8"?>\n` +
  `<urlset xmlns="http://www.sitemap.org/0.9">\n`;

urls.forEach(url => {
  sitemap += `  <url>\n`;
  sitemap += `    <loc>${url}</loc>\n`;
  sitemap += `    <lastmod>${today}</lastmod>\n`;
  sitemap += `    <changefreq>weekly</changefreq>\n`;
  sitemap += `    <priority>0.8</priority>\n`;
  sitemap += `  </url>\n`;
});

sitemap += `</urlset>`;

fs.writeFileSync("sitemap.xml", sitemap, "utf8");

console.log("✅ sitemap.xml generated successfully!");
