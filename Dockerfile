FROM mcr.microsoft.com/powershell:7.5.4

# Install PowerShell Universal module
RUN pwsh -Command \
    Set-PSRepository -Name PSGallery -InstallationPolicy Trusted ; \
    Install-Module PowerShellUniversal -Force

WORKDIR /app

CMD ["pwsh"]
