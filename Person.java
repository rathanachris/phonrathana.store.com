Person john = Person.newBuilder()
    .setId(1234)
    .setName("John Doe")
    .setEmail("email@phonrathanaprtner.com")
    .build();
output = new FileOutputStream(args[0]);
john.writeTo(output);
