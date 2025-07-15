<script>
document.getElementById('regi-form').addEventListener('submit', function(e) {
  const firstName = document.querySelector('input[name="first_name"]').value.trim();
  const lastName = document.querySelector('input[name="last_name"]').value.trim();
  const email = document.querySelector('input[name="email"]').value.trim();
  const password = document.querySelector('input[name="password"]').value;
  const gender = document.querySelector('input[name="gender"]:checked');

  if (!firstName || !lastName || !email || !password || !gender) {
    alert("Please fill in all fields correctly.");
    e.preventDefault(); // Stop form submission
  }
});
</script>
