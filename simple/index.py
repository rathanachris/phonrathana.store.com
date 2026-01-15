<!DOCTYPE html>
<html>
<head>
  <script>
    function __cmp(cmd) {
      if (cmd === 'consentStatus') {
        return { consentExists: true };
      }
    }
  </script>
</head>
<body>
  <script>
    var x = __cmp('consentStatus');
    if (x.consentExists) {
      console.log('Consent exists');
    } else {
      console.log('No consent');
    }
  </script>
</body>
</html>