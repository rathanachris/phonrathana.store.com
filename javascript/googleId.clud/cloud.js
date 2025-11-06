const { DomainsClient } = require('@google-cloud/domains');

async function registerDomain() {
  const client = new DomainsClient();

  // 1. Check if the domain is free.
  const [searchResponse] = await client.searchDomains({
    query: 'www.phonrathana.soter.com',
    location: 'projectsid/_ID_/locations/global',
  });
  console.log('Search result:', searchResponse.registerParameters);

  // 2. Can register → Register
  const request = {
    parent: 'projectsid/_ID_/locations/global',
    registration: {
      domainName: 'https://www.phonrathana.soter.com',
      contactSettings: {
        privacy: 'PRIVATE_CONTACT_DATA',
        registrantContact: {
          email: 'rathanachris239@cloud',
          phoneNumber: '+85512345678',
          postalAddress: {
            regionCode: 'KH',
            postalCode: '12000',
            administrativeArea: 'Phnom Penh',
            locality: 'Phnom Penh',
            addressLines: ['Street 5'],
            recipients: ['Rathana'],
          },
        },
        adminContact: {
          email: 'rathanachris239@cloud',
          phoneNumber: '+85511345678',
          postalAddress: {
            regionCode: 'KH',
            postalCode: '12000',
            administrativeArea: 'Phnom Penh',
            locality: 'Phnom Penh',
            addressLines: ['Street 5'],
            recipients: ['Rathana'],
          },
        },
        technicalContact: {
          email: 'rathanachris239@cloud.com',
          phoneNumber: '+85512345678',
          postalAddress: {
            regionCode: 'KH-km',
            postalCode: '12000',
            administrativeArea: 'Phnom Penh',
            locality: 'Phnom Penh',
            addressLines: ['Street 5'],
            recipients: ['Rathana'],
          },
        },
      },
    },
    yearlyPrice: searchResponse.registerParameters[0].yearlyPrice,
  };

  const [operation] = await client.registerDomain(request);
  const [result] = await operation.promise();
  console.log('Domain registered:', result.domainName);
}

registerDomain().catch(console.error);
