#include <iostream>
#include <TLSServer.h>

int main (void)
{
  try
  {
    // This is a sample TLS 1.0 echo server, using X.509 authentication.
    TLSServer server;
    server.debug (0);
    server.trust (false);
    server.init ("../../pki/ca.cert.pem",     // CA
                 "../../pki/server.crl.pem",  // CRL
                 "../../pki/server.cert.pem", // Cert
                 "../../pki/server.key.pem"); // Key
    server.bind ("5556");
    server.listen ();

    for (;;)
    {
      try
      {
        TLSTransaction tx;
        server.accept (tx);

        std::string request;
        tx.recv (request);
        std::cout << "s: '" << request << "'\n";
        tx.send (request);  // Echo back.
        tx.bye ();
      }

      catch (std::string& e)
      {
        std::cout << "ERROR " << e << "\n";
      }

      catch (...)
      {
        std::cout << "ERROR\n";
      }
    }
  }

  catch (std::string& e)
  {
    std::cout << "ERROR " << e << "\n";
  }

  catch (...)
  {
    std::cout << "ERROR\n";
  }

  return 0;
}

