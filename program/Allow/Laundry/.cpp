SSL_library_init();

SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
SSL *ssl = SSL_new(ctx);
SSL_set_fd(ssl, sock);

if ( SSL_connect(ssl) <= 0 ) {
    cout << "SSL connection failed" << endl;
    return 1;
}

SSL_write(ssl, request.c_str(), request.length());

char buf[4096];
int bytes;
while ((bytes = SSL_read(ssl, buf, sizeof(buf))) > 0) {
    cout.write(buf, bytes);
}

SSL_free(ssl);
SSL_CTX_free(ctx);