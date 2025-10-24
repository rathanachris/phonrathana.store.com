const fs = require("fs");

const urls = [
 "https://www.chrisrthana.master.com/home", "https://www.chrisrthana.master.com/about", "https://www.chrisrthana.master.com/products" "https://www.chrisrthana.master.com/review", "https://www.chrisrthana.master.com/contact",
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