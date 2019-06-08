import junit.framework.TestCase;

public class main extends TestCase {

    public static boolean unitTestOfIsValid() {
        UrlValidator validator = new UrlValidator();

        assertTrue("Should be valid",
                validator.isValid("http://www.test.com"));

        assertFalse("Should not be valid",
                validator.isValid("htt://ww.test.com"));

        assertTrue("Should be valid",
                validator.isValid("http://www.test.org"));

        assertFalse("Should not be valid",
                validator.isValid("http://www.test"));

        return true;

    }

    /* REFERENCE: Utilized URL generator for the URLs below */
    public static boolean randomTestOfIsValid() {
        String[] randomURLs = {
                "https://example.net/belief/act.php", "http://www.example.org/air", "https://www.example.com/account/bat#bag",
                "http://example.net/", "http://www.example.net/approval", "http://example.com/art/aunt", "http://www.example.com/amount?border=behavior&animal=birth#afternoon",
                "http://www.example.com/#advertisement", "https://www.example.com/?boot=books&beef=addition", "https://bed.example.com/blade/brake",
                "https://birds.example.com/apparatus.aspx?authority=bath", "http://www.example.com/bait.php#alarm", "https://www.example.com/appliance/baseball"
        };

        UrlValidator validator = new UrlValidator();

        for (int i = 0; i < 1000; i++) {
            assertTrue(validator.isValid(randomURLs[(int)Math.random() * randomURLs.length]));
        }

        return true;
    }

    public static boolean testValidatorSuite() {
        UrlValidatorTest urltest = new UrlValidatorTest("Test");
        urltest.testValidator202();
        urltest.testValidator204();
        urltest.testValidator235();
        urltest.testValidator248();
        urltest.testValidator276();
        urltest.testValidator288();
        urltest.testValidator290();
        urltest.testValidator309();
        urltest.testValidator339();
        urltest.testValidator339IDN();
        urltest.testValidator342();
        urltest.testValidator218();
        urltest.testValidator391FAILS();
        urltest.testValidator391OK();
        urltest.testValidator411();
        urltest.testValidator420();

        return true;
    }

    public static boolean testIsValidTest() {
        UrlValidatorTest urltest = new UrlValidatorTest("Test");
        urltest.testIsValid();

        return true;
    }

    public static void main(String []args) {

        System.out.println("Unit Test:");
        System.out.println("Testing isValid & testIsValid functions:");

        System.out.println("Test: \'unitTestIsValid\'");
        if (unitTestOfIsValid())
            System.out.println("PASS");
        else
            System.out.println("FAIL");
        System.out.println();

        System.out.println("Test: \'testValidatorSuite\'");
        if (testValidatorSuite())
            System.out.println("PASS");
        else
            System.out.println("FAIL");

        System.out.println();
        System.out.println("Test: \'testIsValidTest\'");
        if (testIsValidTest())
            System.out.println("PASS");
        else
            System.out.println("FAIL");

        System.out.println();
        System.out.println("Test: \'randomTestIsValid\'");
        if (randomTestOfIsValid())
            System.out.println("PASS");
        else
            System.out.println("FAIL");

    }
}

