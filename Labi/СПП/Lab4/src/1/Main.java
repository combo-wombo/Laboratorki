import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        City Brest = new City(
        new String[] {"Prosp 1", "Prospectt", "проспекt 3"},
        new String[] {"Улица Гвардейская", "Ул. Борща"},
        new String[] {"A1", "A2", "A3", "A4", "A5"});
        Brest.printProspects();
        Brest.printAreas();
        Brest.printStreets();
        Brest.addProspect("ПРОСПЕКТ_НОВЫЙЙ");
        Brest.removeStreet("Улица Гвардейская");
        Brest.printProspects();
        Brest.printStreets();
        Brest.setAreas(new String[] {"Tiananmen Square000_000_000", "ar2"});
        Brest.printAreas();
    }

}
class City {

    public static class CityChild {
        private ArrayList<String> prospects;
        private ArrayList<String> streets;
        private ArrayList<String> areas;

        public CityChild(String[] prospects, String[] streets, String[] areas) {
            this.prospects  = new ArrayList<>(Arrays.asList(prospects));
            this.streets    = new ArrayList<>(Arrays.asList(streets));
            this.areas      = new ArrayList<>(Arrays.asList(areas));
        }
    }

    private CityChild obj;

    public City(String[] prospects, String[] streets, String[] areas) {
        obj = new CityChild(prospects, streets, areas);
    }

    public void printProspects() {
        int count = 0;
        System.out.println("\n==Prospects=====");
        for (String prospect : obj.prospects) {
            System.out.println(count + ": " + prospect);
            count++;
        }
        System.out.println("================");
    }

    public void printStreets() {
        int count = 0;
        System.out.println("\n==Streets=======");
        for (String street : obj.streets) {
            System.out.println(count + ": " + street);
            count++;
        }
        System.out.println("================");
    }

    public void printAreas() {
        int count = 0;
        System.out.println("\n==Areas=========");
        for (String area : obj.areas) {
            System.out.println(count + ": " + area);
            count++;
        }
        System.out.println("================");
    }

    public void addProspect(String prospect) {
        System.out.println("Adding " + prospect);
        obj.prospects.add(prospect);
    }

    public void addStreet(String street) {
        System.out.println("Adding " + street);
        obj.streets.add(street);
    }

    public void addArea(String area) {
        System.out.println("Adding " + area);
        obj.areas.add(area);
    }

    public void removeProspect(String prospect) {
        System.out.println("Removing " + prospect);
        obj.prospects.remove(prospect);
    }

    public void removeStreet(String street) {
        System.out.println("Removing " + street);
        obj.streets.remove(street);
    }

    public void removeArea(String area) {
        System.out.println("Removing " + area);
        obj.areas.remove(area);
    }

    public void setProspects(String[] prospects) {
        System.out.println("Setting prospects...");
        obj.prospects = new ArrayList<>(Arrays.asList(prospects));
    }

    public void setStreets(String[] streets) {
        System.out.println("Setting streets...");
        obj.streets = new ArrayList<>(Arrays.asList(streets));
    }

    public void setAreas(String[] areas) {
        System.out.println("Setting areas...");
        obj.areas = new ArrayList<>(Arrays.asList(areas));
    }
}