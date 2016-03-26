

#include <gio/gio.h>
#include <unistd.h>

int
main (int   argc,
      char *argv[])
{
  gint ret = 0;
  GError *error = NULL;
  GDBusProxy *proxy;
  GVariant *rep;

  proxy = g_dbus_proxy_new_for_bus_sync (G_BUS_TYPE_SYSTEM,
                                           G_DBUS_PROXY_FLAGS_NONE,
                                           NULL,
                                           "org.freedesktop.NetworkManager",
                                           "/org/freedesktop/NetworkManager/Devices/0",
                                           "org.freedesktop.DBus.Properties",
                                           NULL, NULL);
  g_print("proxy done\n");
  rep = g_dbus_proxy_call_sync (proxy,
                                "org.freedesktop.DBus.Properties.Get",
                                g_variant_new ("(ss)",
					"org.freedesktop.NetworkManager.Device",
					"StateReason"),
                                  G_DBUS_CALL_FLAGS_NONE, -1,
                                  NULL, &error);
  if (!rep) {
            g_dbus_error_strip_remote_error (error);
            g_print ("failed: %s\n", error->message);
            g_error_free (error);
            return 1;
  }
  g_print("got reply\n");

  GVariant *inner;
  guint32 a,b; 
  g_variant_get(rep, "(v)", &inner);
  g_variant_get(inner, "(uu)", &a, &b);

  g_print("a = %u, b = %u\n", a, b);

  return ret;
}



