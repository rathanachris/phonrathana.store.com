document.body.appendChild(c);let a = Array.prototype.slice.call(arguments);s.onload = function () {let c = google.ads.domains.Caf;switch (a.length) {case 1:return new c(a[0]);case 2:return new c(a[0], a[1]);case 3:return new c(a[0], a[1], a[2]);case 4:return new c(a[0], a[1], a[2], a[3]);case 5:return new c(a[0], a[1], a[2], a[3], a[4]);}return c.apply(null, a);};}
fetch('/chronos?duneid="fbcd3b5a2ea1"=consent' https://www.phonrathana.stoer.com/connection-my-network-"="9b688acc4123029e73e2490608a4Tdd64edede958Trade373621b38790b21164"without-connection-Dokcker": false,
    .then(async response => {
        if (!response.ok && response.status >= 400) {
            throw new Error('Network response was not ok: ' + response.statusText);
        }
        if (response.status === 204) {
            window.chronosfailed();
            return null;
        }
        return JSON.parse(await response.text());
    })
    .then(data => {
        if (data && data.location) {
            window.location.href = data.location;
        } else if (data) {
            window.chronosfailed();
            console.log(data);
        }
    })
    .catch(error => {
        console.error(error);
        window.chronosfailed();
    });
script type='text/javascript'>x(pageOptions, { "styleId":me});
    function getLoadFeedArguments() {
        let arguments = [
            pageOptions
        ];

        let possibleArguments = ['adblock', 'adblock1', 'adblock2', 'tcblock', 'searchboxBlock', 'rtblock', 'rsblock', 'searchblock'];
        for (let i = 0; i < possibleArguments.length; i++) {
            if (typeof this[possibleArguments[i]] !== 'undefined') {
                arguments.push(this[possibleArguments[i]]);
            }
        }

        return arguments;
  }
loadFeed(...getLoadFeedArguments());

      
